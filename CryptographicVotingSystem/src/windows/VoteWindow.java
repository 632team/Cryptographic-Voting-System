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

public class VoteWindow {

	protected Shell shell;
	private Label lblid;
	private Voter voter;
	private Text text;
	private Text text_1;
	private Text text_2;
	private Text text_3;
	private Text text_4;
	
	public VoteWindow() {}
	
	public VoteWindow(Voter voter) {
		this.voter = voter;
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
		shell.setSize(437, 335);
		shell.setText("\u4E2A\u4EBA\u4FE1\u606F");
		
		Label label = new Label(shell, SWT.NONE);
		label.setBounds(50, 41, 43, 17);
		label.setText("\u59D3\u540D\uFF1A");
		
		Label label_1 = new Label(shell, SWT.NONE);
		label_1.setText("\u5E74\u9F84\uFF1A");
		label_1.setBounds(50, 85, 43, 17);
		
		Label label_2 = new Label(shell, SWT.NONE);
		label_2.setText("\u6027\u522B\uFF1A");
		label_2.setBounds(50, 135, 43, 17);
		
		lblid = new Label(shell, SWT.NONE);
		lblid.setText("  \u6295\u7968ID\uFF1A");
		lblid.setBounds(27, 182, 66, 17);
		
		text = new Text(shell, SWT.BORDER | SWT.READ_ONLY);
		text.setEnabled(false);
		text.setBounds(99, 35, 108, 23);
		text.setText(voter.getName());
		
		text_1 = new Text(shell, SWT.BORDER | SWT.READ_ONLY);
		text_1.setEnabled(false);
		text_1.setBounds(99, 79, 108, 23);
		text_1.setText(String.valueOf(voter.getAge()));
		
		text_2 = new Text(shell, SWT.BORDER | SWT.READ_ONLY);
		text_2.setEnabled(false);
		text_2.setBounds(99, 129, 108, 23);
		text_2.setText(voter.getSex());
		
		text_3 = new Text(shell, SWT.BORDER | SWT.READ_ONLY);
		text_3.setEnabled(false);
		text_3.setBounds(99, 176, 108, 23);
		text_3.setText(String.valueOf(voter.getId()));
		
		Button button = new Button(shell, SWT.NONE);
		// 选择候选人
		button.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				new CandidateListWindow().open();
			}
		});
		button.setBounds(288, 80, 80, 27);
		button.setText("\u9009\u62E9\u5019\u9009\u4EBA");
		
		Button button_1 = new Button(shell, SWT.NONE);
		// 发送投票信息
		button_1.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				
			}
		});
		button_1.setEnabled(false);
		button_1.setBounds(178, 233, 80, 27);
		button_1.setText("\u6295\u7968");
		
		text_4 = new Text(shell, SWT.BORDER | SWT.READ_ONLY);
		text_4.setEnabled(false);
		text_4.setText("\u672A\u9009\u62E9\u5019\u9009\u4EBA");
		text_4.setBounds(277, 129, 108, 23);
	}
}
