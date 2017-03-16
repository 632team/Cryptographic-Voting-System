package windows;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartFrame;
import org.jfree.chart.JFreeChart;
import org.jfree.data.general.DefaultPieDataset;

import dao.Dao;
import dao.model.Result;
import javafx.scene.control.cell.MapValueFactory;

import java.sql.*;
import java.util.*;

import javax.swing.JOptionPane;

public class ResultWindow {
	public ResultWindow() {
		DefaultPieDataset dpd=new DefaultPieDataset(); //����һ��Ĭ�ϵı�ͼ
    	Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    	
    	List<Result> result = Dao.getVoterResult();
    	for (int i = 0; i < result.size(); ++i){
    		int id = result.get(i).getCandidate_id();
    		if (map.get(id) != null){
    			map.put(id, map.get(Integer.toString(id)) + 1);
    		}else{
    			map.put(id, 1);
    		}
    	}
    	
    	for (Map.Entry<Integer, Integer> entry : map.entrySet()) {  
    		  
    	    System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());  
    	    String keyString = Dao.getCandidatebyId(entry.getKey()).getName();
    	    int number = entry.getValue();
    	    dpd.setValue(keyString, number);
    	}  
     
       // dpd.setValue("������Ա", 25);  //��������
       // dpd.setValue("�г���Ա", 25);
       // dpd.setValue("������Ա", 45);
       // dpd.setValue("������Ա", 10);
        
        JFreeChart chart=ChartFactory.createPieChart("ͶƱ���",dpd,true,true,false); 
        //���Բ�����API�ĵ�,��һ�������Ǳ��⣬�ڶ���������һ�����ݼ���������������ʾ�Ƿ���ʾLegend�����ĸ�������ʾ�Ƿ���ʾ��ʾ�������������ʾͼ���Ƿ����URL
        
        ChartFrame chartFrame=new ChartFrame("ͶƱ���",chart); 
        //chartҪ����Java��������У�ChartFrame�̳���java��Jframe�ࡣ�õ�һ�������������Ƿ��ڴ������Ͻǵģ��������м�ı��⡣
        chartFrame.pack(); //�Ժ��ʵĴ�Сչ��ͼ��
        chartFrame.setVisible(true);//ͼ���Ƿ�ɼ�
	}
}
