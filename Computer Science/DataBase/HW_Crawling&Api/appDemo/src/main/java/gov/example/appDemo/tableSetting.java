//tableSetting.java


package gov.example.appDemo;
//import org.springframework.stereotype.Controller;
//import org.springframework.web.bind.annotation.RequestParam;

import java.sql.*;
//import java.util.ArrayList;
import java.util.Properties;


public class tableSetting {
	static Connection conn;
	
	//서버 시작시 포스트그래스와 연결, 생성자임
	public void tableSet() throws SQLException
	{
		
		String url = "jdbc:postgresql://localhost/hongik";
		
		
		Properties props = new Properties();
		props.setProperty("user", "postgres");
		props.setProperty("password", "1234");
		conn = DriverManager.getConnection(url, props);
		
		 
		 DatabaseMetaData metadata = conn.getMetaData();
		 
		 ResultSet resultSet = metadata.getTables(null, null, "students", null);
		 
		 if(resultSet.next()){
		   
		      System.out.println("Table exists");
		  
		}
		 
		 
			        			
				
}

		
	
}
