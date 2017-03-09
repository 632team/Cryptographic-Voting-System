package windows;

import dao.Dao;

public class Main {
	public static void main(String[] args) {
		Dao dao = Dao.getInstance();
		new LoginWindow().open();
	}
}
