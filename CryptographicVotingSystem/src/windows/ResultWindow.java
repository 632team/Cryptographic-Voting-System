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
		DefaultPieDataset dpd=new DefaultPieDataset(); //建立一个默认的饼图
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
     
       // dpd.setValue("管理人员", 25);  //输入数据
       // dpd.setValue("市场人员", 25);
       // dpd.setValue("开发人员", 45);
       // dpd.setValue("其他人员", 10);
        
        JFreeChart chart=ChartFactory.createPieChart("投票结果",dpd,true,true,false); 
        //可以查具体的API文档,第一个参数是标题，第二个参数是一个数据集，第三个参数表示是否显示Legend，第四个参数表示是否显示提示，第五个参数表示图中是否存在URL
        
        ChartFrame chartFrame=new ChartFrame("投票结果",chart); 
        //chart要放在Java容器组件中，ChartFrame继承自java的Jframe类。该第一个参数的数据是放在窗口左上角的，不是正中间的标题。
        chartFrame.pack(); //以合适的大小展现图形
        chartFrame.setVisible(true);//图形是否可见
	}
}
