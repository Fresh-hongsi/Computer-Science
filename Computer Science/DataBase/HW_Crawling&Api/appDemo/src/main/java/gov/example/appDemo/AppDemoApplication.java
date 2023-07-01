//AppDemoApplication.java

package gov.example.appDemo;

//import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;

//import javax.lang.model.util.Elements;

//import org.jsoup.Jsoup;
//import org.jsoup.nodes.Document;
//import org.springframework.beans.factory.annotation.Autowired;
//import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
//import org.springframework.jdbc.core.JdbcTemplate;

@SpringBootApplication
public class AppDemoApplication  {

   //@Autowired
    //private JdbcTemplate jdbcTemplate;
   
  
   public static void main(String[] args) throws SQLException {
	   
	   
      SpringApplication.run(AppDemoApplication.class, args);
      
      studentCrawler student = new studentCrawler();
      ArrayList<studentVO>SV=new ArrayList<studentVO>(); 
	  student.crawling("https://apl.hongik.ac.kr/lecture/dbms",SV);
	 
	  
	  //테이블 존재 확인 
	  tableSetting tableSetter=new tableSetting();
	  tableSetter.tableSet();
	  
	  //크롤링한 데이터를 테이블에 넣기 -> 중복 확인 후 새로 추가된 데이터만 테이블에 넣기
	  studentUpload.uploadDB(SV);
	  
      
     
   }
   
   
}

