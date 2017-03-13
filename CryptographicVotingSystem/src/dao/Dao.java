package dao;

import java.sql.*;
import java.util.*;

import javax.swing.JOptionPane;

import dao.model.*;

public class Dao {
		// 定义数据库驱动类的名称
		protected static String dbClassName = "com.mysql.jdbc.Driver";
		// 定义访问数据库的URL
		protected static String dbUrl;
		// 定义访问数据库的用户名
		protected static String dbUser = "root";
		// 定义访问数据库的密码
		protected static String dbPwd = "team632";
		// 声明数据库连接对象
		private static Connection conn = null;
		// 声明数据接入对象
		public static Dao dao = new Dao();
		
		private Dao() {
			try {
				if (conn == null) {
					String ip = "139.224.134.144";
					dbUrl = "jdbc:mysql://" + ip + "/cryptographic_voting_system?useUnicode=true&characterEncoding=utf-8";
					Class.forName(dbClassName).newInstance();
					conn = DriverManager.getConnection(dbUrl, dbUser, dbPwd);
					System.out.println("数据库连接成功。");
				}
			} catch (Exception e) {
				String message = e.getMessage();
				int index = message.lastIndexOf(')');
				message = message.substring(index + 1);
				JOptionPane.showMessageDialog(null, message);
				e.printStackTrace();
			}
		}
		
		// 得到Data Access Object
		public static Dao getInstance() {
			return dao;
		}
		
		
		//--------------------数据库操作模块---------------------------//
		// 创建数据库查询
		public static ResultSet findForResultSet(String sql) {  
	        if (conn == null)  
	            return null;
	        // long time = System.currentTimeMillis();//返回以毫秒为单位的当前时间  
	        ResultSet rs = null;
	        try {
	        	//该常量指示可滚动但通常不受result底层数据更改影响的result对象的类型，不可更新的resultset对象的类型  
	            Statement stmt = null;
	            stmt = conn.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,
						ResultSet.CONCUR_UPDATABLE);
	            rs = stmt.executeQuery(sql);
	        // second = ((System.currentTimeMillis() - time) / 1000d) + "";
	        } catch (SQLException e) {
	        	String message = e.getMessage();
				int index = message.lastIndexOf(')');
				message = message.substring(index + 1);
				JOptionPane.showMessageDialog(null, message);
	            e.printStackTrace();
	        }
	        return rs;
		}

		// 插入数据库
		public static boolean insert(String sql) {
			boolean rs = false;
			try {
				Statement stmt= conn.createStatement();
				if (stmt.executeUpdate(sql) > 0) rs = true;
			} catch (SQLException e) {
				e.printStackTrace();
				String message = e.getMessage();
				int index = message.lastIndexOf(')');
				message = message.substring(index + 1);
				System.out.println(message);
				return false;
			}
			return rs;
		}
		
		// 更新数据库
		public static boolean update(String sql) {
			return insert(sql);
		}
		
		// 删除数据库
		public static boolean delete(String sql) {
			return insert(sql);
		}
		
		// 验证用户名、密码是否合法
		public static Voter checkLogin(String ic, String pwd) throws SQLException {
			//System.out.println(ic);
			//System.out.println(pwd);
			Voter ret = new Voter();
			ResultSet rs = findForResultSet("select * from voter_information where voter_ic = '" + ic +
					"' and voter_password = '" + pwd + "'");
			if (rs.next()) {
				ret.setId(Integer.parseInt(rs.getString("voter_id")));
				ret.setName(rs.getString("voter_name").trim());
				ret.setAge(Integer.parseInt(rs.getString("voter_age")));
				ret.setSex(rs.getString("voter_sex").trim());
				ret.setIc(rs.getString("voter_ic").trim());
				ret.setPassword(rs.getString("voter_password").trim());
			}
			return ret;
		}
		
		//---------------------添加信息模块----------------------------//
		// 添加投票人信息
		public static boolean insertVoterInfo (Voter vt) {
			try {
				boolean autoCommit = conn.getAutoCommit();
				conn.setAutoCommit(false);
				String sql = "INSERT INTO  `voter_information` (  `voter_name` ,  `voter_age` ,  `voter_sex` ,  `voter_ic` ,  `voter_password` )"
						+ "VALUES ('" + vt.getName() + "', " + vt.getAge() + ",  '" + vt.getSex() 
						+ "', '" + vt.getIc() + "',  '" + vt.getPassword() + "')";
				//System.out.println(sql);
				if (!insert(sql)) {
					JOptionPane.showMessageDialog(null, "注册失败，ID已存在");
					return false;
				}
				conn.commit();
				conn.setAutoCommit(autoCommit);
			} catch (SQLException e) {
				String message = e.getMessage();
				int index = message.lastIndexOf(')');
				message = message.substring(index + 1);
				JOptionPane.showMessageDialog(null, message);
				e.printStackTrace();
				return false;
			}
			return true;
		}
		
		// 添加投票信息
		public static boolean voteCandidate(int vid, int cid) {
			String sql = "INSERT INTO  `voter_result` (  `voter_id` ,  `candidate_id`)"
					+ "VALUES ('" + vid + "', '" + cid + "')";
			return insert(sql);
		}
		
		//---------------------查询信息模块----------------------------//
		// 查询候选人信息
		public static List<Candidate> getCandidateInfo() {
			List<Candidate> list = new ArrayList<Candidate>();
			ResultSet set = findForResultSet("select * from candidate_information" );
			try {
				while (set.next()) {
					Candidate info = new Candidate();
					info.setId(Integer.parseInt(set.getString("candidate_id").trim()));
					info.setName(set.getString("candidate_name").trim());
					info.setAge(Integer.parseInt(set.getString("candidate_age").trim()));
					info.setIc(set.getString("candidate_ic").trim());
					info.setRecord(set.getString("candidate_record").trim());
					info.setSex(set.getString("candidate_sex").trim());
					info.setDelcaration(set.getString("candidate_declaration"));
					list.add(info);
				}
			} catch (SQLException e) {
				String message = e.getMessage();
				int index = message.lastIndexOf(')');
				message = message.substring(index + 1);
				JOptionPane.showMessageDialog(null, message);
				e.printStackTrace();
			}
			return list;
		}
		
		// 通过id查询候选人信息
		public static Candidate getCandidatebyId(int id){
			Candidate info = null;
			ResultSet set = findForResultSet("select * from candidate_information "
					+"where candidate_id = '"+id 	+"'");
			try{
				while(set.next()){
					info = new Candidate();
					info.setId(Integer.parseInt(set.getString("candidate_id").trim()));
					info.setName(set.getString("candidate_name").trim());
					info.setAge(Integer.parseInt(set.getString("candidate_age").trim()));
					info.setIc(set.getString("candidate_ic").trim());
					info.setRecord(set.getString("candidate_record").trim());
					info.setSex(set.getString("candidate_sex").trim());
					info.setDelcaration(set.getString("candidate_declaration"));
				}
			}catch (SQLException e) {
				String message = e.getMessage();
				int index = message.lastIndexOf(')');
				message = message.substring(index + 1);
				JOptionPane.showMessageDialog(null, message);
				e.printStackTrace();
			}
			return info;
		}
		
		// 查询投票结果
		public static List<Result> getVoterResult() {
			List<Result> list = new ArrayList<Result>();
			ResultSet set = findForResultSet("select * from voter_result" );
			try {
				while (set.next()) {
					Result info = new Result();
					info.setVoter_id(set.getInt("voter_id"));
					info.setCandidate_id(set.getInt("candidate_id"));
					list.add(info);
				}
			} catch (SQLException e) {
				String message = e.getMessage();
				int index = message.lastIndexOf(')');
				message = message.substring(index + 1);
				JOptionPane.showMessageDialog(null, message);
				e.printStackTrace();
			}
			return list;
		}
}
