//StudentCrawler.java

package gov.example.appDemo;
import java.io.IOException;
import java.util.Iterator;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import java.util.ArrayList;



public class studentCrawler implements Crawler {
	
	public void crawling(String url,ArrayList<studentVO> SV)
	{
		Document doc = null;
		
		//int idx=1;
		try {
			doc=Jsoup.connect(url).get();
			
			
			//Elements List1 = doc.select(".jXK9ad-SmKAyb ul:nth-child(3)");
			//Elements List2 = doc.select(".jXK9ad-SmKAyb ul:nth-child(6)");
			//Elements List3 = doc.select(".jXK9ad-SmKAyb ul:nth-child(10)");
			Elements sList= doc.getElementsByClass("n8H08c UVNKR");
			
			//Iterator<Element> ie1 = sList.get(0).select("li").iterator();
		
			
			String degreeString=doc.select("h2").text();
			String[] degreeList=degreeString.split(" ");
			String degree1=degreeList[0].toLowerCase();
			String degree2=degreeList[2].toLowerCase();
			String degree3=degreeList[4].toLowerCase();
			
			if(degree1.equals("undergraduate"))
			{
				degree1="undergrad";
			}
			
			if(degree2.equals("undergraduate"))
			{
				degree2="undergrad";
			}
			
			if(degree3.equals("undergraduate"))
			{
				degree3="undergrad";
			}
			
			System.out.println(degree1);
			System.out.println(degree2);
			System.out.println(degree3);
			
			
			System.out.println("---------firstDegree---------");
			Iterator<Element> ie1 = sList.get(0).select("li").iterator();
			
			
			String[] splitDegree1 = null;
			while(ie1.hasNext())
			{
				
				
				
				String List1Info =ie1.next().text();
				
				splitDegree1=List1Info.split(", ");
				String name = splitDegree1[0];
				String email=splitDegree1[1];
				int graduation=Integer.parseInt(splitDegree1[2]);
				
				
				SV.add(new studentVO(name,email,degree1,graduation));
				//idx++;
				
				
				for(int i=0;i<3;i++)
				{
					System.out.println(splitDegree1[i]);
					
				}
				
						
			}
			
			
			System.out.println("---------secondDegree---------");
			Iterator<Element> ie2 = sList.get(1).select("li").iterator();
			
			String[] splitDegree2 = null;
			while(ie2.hasNext())
			{
				
				String List2Info =ie2.next().text();
				
				splitDegree2=List2Info.split(", ");
				String name = splitDegree2[0];
				String email=splitDegree2[1];
				int graduation=Integer.parseInt(splitDegree2[2]);
				
				
				SV.add(new studentVO(name,email,degree2,graduation));
				//idx++;
				//masters.concat(ie2.next().text());
				for(int i=0;i<3;i++)
				{
					System.out.println(splitDegree2[i]);
					
				}
				//System.out.println(ie2.next().text());
			}
			
			System.out.println("---------thirdDegree---------");
			Iterator<Element> ie3 = sList.get(2).select("li").iterator();
			
			String[] splitDegree3 = null;
			while(ie3.hasNext())
			{
				String List3Info =ie3.next().text();
				
				splitDegree3=List3Info.split(", ");
				String name = splitDegree3[0];
				String email=splitDegree3[1];
				int graduation=Integer.parseInt(splitDegree3[2]);
				
				
				SV.add(new studentVO(name,email,degree3,graduation));
				//idx++;
				//undergrads.concat(ie3.next().text());
				for(int i=0;i<3;i++)
				{
					System.out.println(splitDegree3[i]);
					
				}
				
				//System.out.println(ie3.next().text());
			}
			
			for (studentVO item:SV )
			{
				System.out.println(String.format("%s %s %s %d",item.name,item.email,item.degree,item.graduation));
			}
		
		
		}catch(IOException e)
		{
			e.printStackTrace();
		}
		

	}
	

}