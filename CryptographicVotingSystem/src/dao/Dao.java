package dao;

import java.sql.*;

import javax.swing.JOptionPane;

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
		
		// 在静态代码段中初始化Dao类，实现数据库的驱动和连接。(PS:此块只初始化一次)
		static {
			try {
				if (conn == null) {
					String ip = "139.224.134.144";
					String port = "3306";
					dbUrl = "jdbc:mysql://" + ip + "/cryptographic_voting_system";
					Class.forName(dbClassName).newInstance();
					conn = DriverManager.getConnection(dbUrl, dbUser, dbPwd);
				}
			} catch (Exception e) {
				String message = e.getMessage();
				int index = message.lastIndexOf(')');
				message = message.substring(index + 1);
				JOptionPane.showMessageDialog(null, message);
				e.printStackTrace();
			}
		}
		
		private Dao() {}
		
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
				JOptionPane.showMessageDialog(null, message);
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
}
