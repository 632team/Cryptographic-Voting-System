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
		private static Connection conn = null;
		// �������ݽ������
		public static Dao dao = new Dao();
		
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
		
		private Dao() {}
		
		// �õ�Data Access Object
		public static Dao getInstance() {
			return dao;
		}
		
		//--------------------���ݿ����ģ��---------------------------//
		// �������ݿ��ѯ
		public static ResultSet findForResultSet(String sql) {  
	        if (conn == null)  
	            return null;
	        // long time = System.currentTimeMillis();//�����Ժ���Ϊ��λ�ĵ�ǰʱ��  
	        ResultSet rs = null;
	        try {
	        	//�ó���ָʾ�ɹ�����ͨ������result�ײ����ݸ���Ӱ���result��������ͣ����ɸ��µ�resultset���������  
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
		
		// �������ݿ�
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
		
		// �������ݿ�
		public static boolean update(String sql) {
			return insert(sql);
		}
		
		// ɾ�����ݿ�
		public static boolean delete(String sql) {
			return insert(sql);
		}
}
