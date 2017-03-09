package windows;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.wb.swt.SWTResourceManager;

import dao.model.Voter;

public class Login {

	protected Shell shell;
	private Text text;
	private Text text_1;
	private Voter voter = new Voter();

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			Login window = new Login();
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
		shell.setSize(450, 300);
		shell.setText("登录");
		
		Label label = new Label(shell, SWT.NONE);
		label.setBounds(102, 86, 61, 17);
		label.setText("\u7528\u6237\u540D\uFF1A");
		
		Label label_1 = new Label(shell, SWT.NONE);
		label_1.setBounds(102, 130, 61, 17);
		label_1.setText("\u5BC6   \u7801\uFF1A");
		
		text = new Text(shell, SWT.BORDER);
		text.setBounds(159, 80, 171, 23);
		
		text_1 = new Text(shell, SWT.BORDER | SWT.PASSWORD);
		text_1.setBounds(159, 124, 171, 23);
		
		Button button = new Button(shell, SWT.NONE);
		button.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				voter.setIc(text.getText().trim());
				voter.setPassword(text_1.getText().trim());
				System.out.println(voter.getIc());
			}
		});
		button.setBounds(128, 171, 81, 27);
		button.setText("\u767B\u5F55");
		
		Button button_1 = new Button(shell, SWT.NONE);
		button_1.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				
			}
		});
		button_1.setText("注册");
		button_1.setBounds(236, 171, 81, 27);
		
		Label label_2 = new Label(shell, SWT.NONE);
		label_2.setFont(SWTResourceManager.getFont("微软雅黑", 16, SWT.NORMAL));
		label_2.setBounds(86, 23, 322, 40);
		label_2.setText("\u6B22\u8FCE\u4F7F\u7528\u533F\u540D\u7535\u5B50\u6295\u7968\u7CFB\u7EDF");

	}
	
	// 得到投票人信息
	public Voter getVoter() {
		return voter;
	}
}
