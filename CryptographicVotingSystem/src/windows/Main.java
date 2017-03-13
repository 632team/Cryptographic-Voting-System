package windows;

import dao.Dao;

public class Main {
	public static void main(String[] args) {
		Thread back = new Thread(new Runnable() {
			public void run() {
				// TODO Auto-generated method stub
				Dao.getInstance();
			}
		});
		back.start();
		new LoginWindow().open();
		System.exit(0);
	}
}
