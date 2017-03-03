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
		public static Connection conn = null;
		
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
}
