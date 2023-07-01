//DemoController.java

package gov.example.appDemo.controller;


import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import java.sql.*;
import java.util.Properties;


//Annotation

@Controller
@RequestMapping("/students")
@ResponseBody


//Class
public class DemoController {
	Connection conn;
	
	//서버 시작시 포스트그래스와 연결, 생성자임
	public DemoController() throws SQLException
	{
		String url = "jdbc:postgresql://localhost/hongik";
		Properties props = new Properties();
		props.setProperty("user", "postgres");
		props.setProperty("password", "1234");
		conn = DriverManager.getConnection(url, props);
	}
	
	
	
	
	@GetMapping("/degree")
	@ResponseBody
	public String studentDegree (@RequestParam(value="name")String name) throws SQLException {
		
		String result=new String();
		try(PreparedStatement pst = conn.prepareStatement("SELECT s.name, s.degree FROM students s WHERE s.name=?");) 
		{
	        pst.setString(1, name);
	        ResultSet rs = pst.executeQuery();
	        String d=new String();
	        int counter=0;
	        
	        while (rs.next()) {
	        	
	        	counter=counter+1;
	        	if(counter>1)
	        	{
	        		result="There are multiple students with the same name. Please provide an email address instead.";
	        	}
	        	
	        	
	        	else if(counter==1)
	        	{
	        		d=rs.getString("degree");
	        		if(d.equals("phd"))
	        		{
	        			d="phd";
	        		}
	        		
	        		if(d.equals("master"))
	        		{
	        			d="master";
	        		}
	        		
	        		if(d.equals("undergrad"))
	        		{
	        			d="undergrad";
	        		}
	        		
	        		
	        		result=rs.getString("name") + " : " + d;
	        	}
	        	
	            
	            
	        }
	        
	        if(counter==0)
        	{
        		result="No such student";
        	}
	        
	        
	    }
	    // Handle any errors that may have occurred.
	    catch (SQLException e) {
	        e.printStackTrace();
	    }
		
		return result;
		
	}
	
	
	@GetMapping("/email")
	@ResponseBody
	public String studentEmail (@RequestParam(value="name")String name) throws SQLException {
		
		String result=new String();
		try(PreparedStatement pst = conn.prepareStatement("SELECT s.name, s.email FROM students s WHERE s.name=?");) 
		{
	        pst.setString(1, name);
	        ResultSet rs = pst.executeQuery();
	        
	        int counter=0;
	        
	        while (rs.next()) {
	        	
	        	counter=counter+1;
	        	if(counter>1)
	        	{
	        		result="There are multiple students with the same name. Please contact the administrator by phone.";
	        	}
	        	
	        	
	        	else if(counter==1)
	        	{
	        		result=rs.getString("name") + " : " + rs.getString("email");
	        	}
	        	
	            
	            
	        }
	        
	        if(counter==0)
        	{
        		result="No such student";
        	}
	        
	        
	    }
	    // Handle any errors that may have occurred.
	    catch (SQLException e) {
	        e.printStackTrace();
	    }
		
		return result;
		
	}
	
	
	@GetMapping("/stat")
	@ResponseBody
	public String studentNumber (@RequestParam(value="degree")String degree) throws SQLException {
		
		String result=new String();
		String d=new String();
		try(PreparedStatement pst = conn.prepareStatement("SELECT COUNT(s.degree) FROM students s WHERE s.degree=?");) 
		{
			
	        pst.setString(1, degree);
	        ResultSet rs = pst.executeQuery();
	        
	   
	        
	        while (rs.next()) {
	        	
	        	if(degree.equals("phd"))
	        	{
	        		d="phd";
	        	}
	        	
	        	if(degree.equals("master"))
	        	{
	        		d="master";
	        	}
	        	
	        	if(degree.equals("undergrad"))
	        	{
	        		d="undergrad";
	        	}
	        	result="Number of "+d+"'s student : "+rs.getString(1);
		        //System.out.println(result);
	        }
	        
	        
	     
	   
	        
	        
	    }
	    // Handle any errors that may have occurred.
	    catch (SQLException e) {
	        e.printStackTrace();
	    }
		
		return result;
		
	}
	
	@PutMapping("register")
	@ResponseBody
	public String updateStudent(@RequestParam(value="name")String name,
			@RequestParam(value="email")String email,@RequestParam(value="degree")String degree,@RequestParam(value="graduation")String graduation) throws SQLException {
		
		
		//이메일 같고 이름 다르면  Already registered -> 기본키 제약조건에 위배
		//이메일 다르고 이름 같으면 Already registered //
		//이메일 같고 이름 같으면  Already registered 
		//이메일 다르고 이름 다르면 Registration Successful
		String result=new String();
		
		
		
		try(PreparedStatement pst = conn.prepareStatement("SELECT COUNT(*) FROM students s WHERE s.name=?");)
		{
			int matchedNameCounter=0;
			
			pst.setString(1,name);
	        ResultSet rs = pst.executeQuery();
	        
	        while (rs.next()) { //현재 같은 사람이 몇명인지 확인
	        	
	        	matchedNameCounter=rs.getInt(1);
	        	
			
	        }
	        
	        System.out.println(matchedNameCounter);
	        if(matchedNameCounter>=1) //한명이상 이메일이 같은 사람이 존재한다면 -> 삽입 거부
	        {
	        	result="Already registered";
	        	return result;
	        }
		}
		catch (SQLException e) {
	        e.printStackTrace();
	    }
		/////////////////////////////////////////////////////////////////////
		try(PreparedStatement pst = conn.prepareStatement("SELECT COUNT(*) FROM students s WHERE s.email=?");)
		{
			int matchedCounter=0;
			
			pst.setString(1,email);
	        ResultSet rs = pst.executeQuery();
	        
	        while (rs.next()) { //현재 같은 사람이 몇명인지 확인
	        	
	        	matchedCounter=rs.getInt(1);
	        	
			
	        }
	        
	        System.out.println(matchedCounter);
	        if(matchedCounter>=1) //한명이상 이메일이 같은 사람이 존재한다면 -> 삽입 거부
	        {
	        	result="Already registered";
	        	return result;
	        }
		}
		catch (SQLException e) {
	        e.printStackTrace();
	    }
		try(PreparedStatement pst = conn.prepareStatement("INSERT INTO students(name,email,degree,graduation) VALUES (?,?,?,?)");) 
		{
			
			
			//pst.setInt(1,idx+1); //sid값은 현재 테이블 가장 큰 sid값 +1 로 설정하여 insert해야함
			pst.setString(1,name);
			pst.setString(2,email);
			pst.setString(3,degree);
			int grad=Integer.parseInt(graduation); 
			pst.setInt(4,grad);
			pst.addBatch();
			pst.executeBatch();
			result="Registration successful";
			return result;
			
			
		}
		catch (SQLException e) {
	        e.printStackTrace();
	    }
		return result;
		
	}

}