//StudentUpload.java

package gov.example.appDemo;
//import org.springframework.stereotype.Controller;
import java.sql.*;
import java.util.ArrayList;
import java.util.Properties;


public class studentUpload {
	static Connection conn;
	
	//서버 시작시 포스트그래스와 연결, 생성자임
	public static void uploadDB(ArrayList<studentVO>SV) throws SQLException
	{
		
		String url = "jdbc:postgresql://localhost/hongik";
		String sql="INSERT INTO students(name, email, degree, graduation) VALUES (?,?,?,?)";
		Properties props = new Properties();
		props.setProperty("user", "postgres");
		props.setProperty("password", "1234");
		conn = DriverManager.getConnection(url, props);
		
		
		
		
		
		System.out.println(SV.size());
		for(int i=0;i<SV.size();i++)
		{
			
			try(PreparedStatement pst2 = conn.prepareStatement("SELECT COUNT(*) FROM students s WHERE s.email=?");)
			{
				int matchedCounter=0;
				
				pst2.setString(1,SV.get(i).email);
		        ResultSet rs = pst2.executeQuery();
		        
		        while (rs.next()) { //현재 같은 사람이 몇명인지 확인
		        	
		        	matchedCounter=rs.getInt(1);
		        	
				
		        }
		        
		        System.out.println(matchedCounter);
		        if(matchedCounter>=1) //한명이상 이메일이 같은 사람이 존재한다면 -> 삽입 거부
		        {
		        	System.out.println("Already registered");
		        	continue;
		        }
		        
		        else { //중복이 없는 새로운 사람이라면 테이블에 등록 진행
		        	PreparedStatement pst=conn.prepareStatement(sql);
		        	
					pst.setString(1,SV.get(i).name);
					pst.setString(2,SV.get(i).email);
					pst.setString(3,SV.get(i).degree);
					pst.setInt(4,SV.get(i).graduation);
					pst.addBatch();
					pst.executeBatch();
					System.out.println("Registration Success");
				}
			}
			catch (SQLException e) {
		        e.printStackTrace();
		    }
			
			
			
			
		
			
		}
		
		
		System.out.println("update completed");
	}
}