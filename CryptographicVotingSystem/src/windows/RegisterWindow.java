package windows;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Label;

import javax.swing.JOptionPane;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;

import dao.Dao;
import dao.model.Voter;

import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Combo;

public class RegisterWindow {

	protected Shell shell;
	private Text text;
	private Text text_1;
	private Text text_3;
	private Label label_3;
	private Text text_4;
	private Label label_4;
	private Text text_5;
	private Label label_5;
	private Combo combo;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			RegisterWindow window = new RegisterWindow();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
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
		shell.setSize(437, 438);
		shell.setText("\u6CE8\u518C");
		
		Label label = new Label(shell, SWT.NONE);
		label.setBounds(70, 41, 43, 17);
		label.setText("\u59D3\u540D\uFF1A");
		
		text = new Text(shell, SWT.BORDER);
		text.setBounds(119, 35, 211, 23);
		
		Label label_1 = new Label(shell, SWT.NONE);
		label_1.setText("\u5E74\u9F84\uFF1A");
		label_1.setBounds(70, 85, 43, 17);
		
		text_1 = new Text(shell, SWT.BORDER);
		text_1.setBounds(119, 79, 211, 23);
		
		Label label_2 = new Label(shell, SWT.NONE);
		label_2.setText("\u6027\u522B\uFF1A");
		label_2.setBounds(70, 135, 43, 17);
		
		text_3 = new Text(shell, SWT.BORDER);
		text_3.setBounds(119, 176, 211, 23);
		
		label_3 = new Label(shell, SWT.NONE);
		label_3.setText("\u8EAB\u4EFD\u8BC1\u53F7\uFF1A");
		label_3.setBounds(47, 182, 66, 17);
		
		text_4 = new Text(shell, SWT.BORDER | SWT.PASSWORD);
		text_4.setBounds(119, 226, 211, 23);
		
		label_4 = new Label(shell, SWT.NONE);
		label_4.setText("\u5BC6\u7801\uFF1A");
		label_4.setBounds(70, 232, 43, 17);
		
		text_5 = new Text(shell, SWT.BORDER | SWT.PASSWORD);
		text_5.setBounds(119, 266, 211, 23);
		
		label_5 = new Label(shell, SWT.NONE);
		label_5.setText("\u786E\u8BA4\u5BC6\u7801\uFF1A");
		label_5.setBounds(47, 272, 66, 17);
		
		Button button = new Button(shell, SWT.NONE);
		button.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				String text_2 = combo.getText();
				if (text.getText() == "" || text_1.getText() == "" || text_2 == "" || text_3.getText() == "" || text_4.getText() == "") {
					JOptionPane.showMessageDialog(null, "请完整填写完整信息。");
					return;
				}
				String name = text.getText().trim();
				int age = Integer.parseInt(text_1.getText().trim());
				String sex = text_2;
				String ic = text_3.getText().trim();
				String password = text_4.getText().trim();
				String password2 = text_5.getText().trim();
				if (!password.equals(password2)) {
					JOptionPane.showMessageDialog(null, "两次密码不对。");
					return;
				}
				Voter voter = new Voter();
				voter.setName(name);
				voter.setAge(age);
				voter.setSex(sex);
				voter.setIc(ic);
				voter.setPassword(password);
				if (Dao.insertVoterInfo(voter)) {
					JOptionPane.showMessageDialog(null, "注册成功！");
					shell.close();
				}
			}
		});
		button.setBounds(250, 316, 80, 27);
		button.setText("\u6CE8\u518C");
		
		combo = new Combo(shell, SWT.READ_ONLY);
		combo.setItems(new String[] {"\u7537", "\u5973"});
		combo.setBounds(119, 132, 88, 25);
		combo.select(0);
	}
}
