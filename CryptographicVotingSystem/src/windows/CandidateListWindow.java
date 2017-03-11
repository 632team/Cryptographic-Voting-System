package windows;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.TableItem;

import dao.Dao;
import dao.model.Candidate;
import java.util.*;

import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.events.DisposeListener;
import org.eclipse.swt.events.DisposeEvent;


public class CandidateListWindow {

	protected Shell shell;
	private Table table;
	private TableColumn tableColumn;
	private TableItem tableItem_1;
	private TableItem tableItem_2;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			CandidateListWindow window = new CandidateListWindow();
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
		shell.setSize(353, 377);
		shell.setText("\u9009\u62E9\u5019\u9009\u4EBA");
		
		table = new Table(shell, SWT.BORDER | SWT.FULL_SELECTION);
		table.setBounds(10, 10, 171, 319);
		table.setHeaderVisible(true);
		table.setLinesVisible(true);
		
		TableColumn tblclmnid = new TableColumn(table, SWT.NONE);
		tblclmnid.setWidth(65);
		tblclmnid.setText("\u5019\u9009\u4EBAID");
		
		tableColumn = new TableColumn(table, SWT.NONE);
		tableColumn.setWidth(100);
		tableColumn.setText("\u5019\u9009\u4EBA\u59D3\u540D");
		
		
		List<Candidate> list = Dao.getCandidateInfo();
		for (final Candidate ca: list) {
			TableItem tableItem= new TableItem(table, SWT.NONE);
			tableItem.addListener(SWT.MouseDoubleClick, new Listener() {
				public void handleEvent(Event arg0) {
					System.out.println(ca.getName());
				}
			});
			tableItem.setText(new String[] {String.valueOf(ca.getId()), ca.getName()});
		}
	}
}
