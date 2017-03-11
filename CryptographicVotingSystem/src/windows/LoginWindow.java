package windows;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Label;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.sql.SQLException;
import java.util.Scanner;

import javax.swing.JOptionPane;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.wb.swt.SWTResourceManager;

import dao.Dao;
import dao.model.Voter;
import org.eclipse.swt.widgets.DateTime;

public class LoginWindow {

	protected Shell shell;
	private Text text;
	private Text text_1;
	private Voter voter;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			LoginWindow window = new LoginWindow();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.exit(0);
	}

	/**
	 * Open the window.
	 */
	public void open() {
		Display display = Display.getDefault();
		createContents();
		shell.open();
		shell.layout();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shell = new Shell();
		shell.setSize(450, 300);
		shell.setText("登录");
		
		Label label = new Label(shell, SWT.NONE);
		label.setBounds(102, 86, 61, 17);
		label.setText("\u7528\u6237\u540D\uFF1A");
		
		Label label_1 = new Label(shell, SWT.NONE);
		label_1.setBounds(102, 130, 61, 17);
		label_1.setText("\u5BC6   \u7801\uFF1A");
		
		text = new Text(shell, SWT.BORDER);
		final File file = new File("login.txt");
		if (!file.exists()) {
			try {
				file.createNewFile();
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		}
		Scanner input;
		try {
			input = new Scanner(file);
			if (input.hasNext())
				text.setText(input.nextLine());
			input.close();
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
		text.setBounds(159, 80, 171, 23);
		
		text_1 = new Text(shell, SWT.BORDER | SWT.PASSWORD);
		text_1.setBounds(159, 124, 171, 23);
		
		Button button = new Button(shell, SWT.NONE);
		button.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				String ic = text.getText().trim();
				String pwd = text_1.getText().trim();
				try {
					voter = Dao.checkLogin(ic, pwd);
					if (voter.getName() == null) {
						JOptionPane.showMessageDialog(null, "输入的用户名或密码错误，请重新输入。");
						text_1.setText("");
						return;
					}
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				System.out.println("登录成功。");
				try {
					new FileOutputStream(file).write(ic.getBytes());
				} catch (FileNotFoundException e1) {
					e1.printStackTrace();
				} catch (IOException e1) {
					e1.printStackTrace();
				}
				new VoteWindow(voter).open();
			}
		});
		button.setBounds(128, 171, 81, 27);
		button.setText("\u767B\u5F55");
		
		Button button_1 = new Button(shell, SWT.NONE);
		button_1.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				new RegisterWindow().open();
			}
		});
		button_1.setText("注册");
		button_1.setBounds(236, 171, 81, 27);
		
		Label label_2 = new Label(shell, SWT.NONE);
		label_2.setFont(SWTResourceManager.getFont("微软雅黑", 16, SWT.NORMAL));
		label_2.setBounds(86, 23, 322, 40);
		label_2.setText("\u6B22\u8FCE\u4F7F\u7528\u533F\u540D\u7535\u5B50\u6295\u7968\u7CFB\u7EDF");

	}
}
