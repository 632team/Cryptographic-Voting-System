package dao;

import java.sql.*;

import javax.swing.JOptionPane;

public class Dao {
		// �������ݿ������������
		protected static String dbClassName = "com.mysql.jdbc.Driver";
		// ����������ݿ��URL
		protected static String dbUrl;
		// ����������ݿ���û���
		protected static String dbUser = "root";
		// ����������ݿ������
		protected static String dbPwd = "team632";
		// �������ݿ����Ӷ���
		public static Connection conn = null;
		
		// �ھ�̬������г�ʼ��Dao�࣬ʵ�����ݿ�����������ӡ�(PS:�˿�ֻ��ʼ��һ��)
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
