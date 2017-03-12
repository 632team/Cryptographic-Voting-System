package windows;


import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.List;

import javax.imageio.ImageIO;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import org.eclipse.jface.resource.ImageDescriptor;
import org.eclipse.jface.resource.ImageRegistry;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.MouseAdapter;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.graphics.ImageData;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.TableItem;
import org.eclipse.swt.widgets.Text;

import dao.Dao;
import dao.model.Candidate;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;

public class CandidateListWindow {

	protected Shell shell;
	private Table table;
	private TableColumn tableColumn;
	private TableItem tableItem_1;
	private TableItem tableItem_2;
	private Text text_intro;
	private Text text_declaration;
	private Text text_age;
	private Text text_name;
	private Label label_picture;
	private List<Candidate> list;
	private int Candidate_id;
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
		setCandidate_id(-1);
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
		shell.setSize(563, 391);
		shell.setText("\u9009\u62E9\u5019\u9009\u4EBA");
		
		table = new Table(shell, SWT.BORDER | SWT.FULL_SELECTION);
		table.setTouchEnabled(true);
		table.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseDoubleClick(MouseEvent e) {
				int index = table.getSelectionIndex();
				System.out.println(index);
				if(index < 0 || index >= list.size()) return ;
				setCandidate_id(list.get(index).getId());
				text_name.setText(list.get(index).getName());
				text_age.setText(String.valueOf(list.get(index).getAge()));
				text_intro.setText(list.get(index).getRecord());
				String path = "http://oh9ex6wd2.bkt.clouddn.com/2.jpg";
//				String path = "https://mail.qq.com/cgi-bin/magick?mailid=ZL2511-LaFYqnC8_MECDStzUCKze73&filename=2.jpg&sid=ujaTTpSeuodCIwVd"
			    ImageRegistry imageRegistry = new ImageRegistry();
//			    Display display = new Display();
	            try {
					imageRegistry.put("Exist", ImageDescriptor.createFromURL(new URL(path)));
				} catch (MalformedURLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}  
			    Image image0 = imageRegistry.get("Exist");  
		        ImageData imageData0 = image0.getImageData();
		        int width = label_picture.getBounds().width;
		        int height = label_picture.getBounds().height;
		        System.out.println(width);
		        System.out.println(height);
		        ImageData imageData1 = imageData0.scaledTo(width, height);
		        width = imageData1.width;
		        height = imageData1.height;
		        System.out.println(width);
		        System.out.println(height);
		        Image image = new Image(null, imageData1);
		        label_picture.setImage(image);
			}
		});
		table.setBounds(10, 10, 171, 319);
		table.setHeaderVisible(true);
		table.setLinesVisible(true);
		
		TableColumn tblclmnid = new TableColumn(table, SWT.NONE);
		tblclmnid.setWidth(65);
		tblclmnid.setText("\u5019\u9009\u4EBAID");
		
		tableColumn = new TableColumn(table, SWT.NONE);
		tableColumn.setWidth(100);
		tableColumn.setText("\u5019\u9009\u4EBA\u59D3\u540D");
		
		Composite composite = new Composite(shell, SWT.NONE);
		composite.setBounds(227, 23, 287, 281);
		
		Label label = new Label(composite, SWT.NONE);
		label.setBounds(24, 42, 61, 17);
		label.setText("\u5019\u9009\u4EBA:");
		
		Label label_1 = new Label(composite, SWT.NONE);
		label_1.setText("\u5E74\u9F84:");
		label_1.setBounds(24, 83, 61, 17);
		
		Label label_2 = new Label(composite, SWT.NONE);
		label_2.setText("\u4E8B\u8FF9\u7B80\u4ECB:");
		label_2.setBounds(24, 207, 61, 17);
		
		text_intro = new Text(composite, SWT.BORDER|SWT.MULTI|SWT.WRAP);
		text_intro.setEnabled(true);
		text_intro.setEditable(false);
		text_intro.setTouchEnabled(true);
		text_intro.setText("");
		text_intro.setBounds(101, 162, 169, 103);
		
		Label label_3 = new Label(composite, SWT.NONE);
		label_3.setBounds(24, 121, 61, 17);
		label_3.setText("\u7ADE\u9009\u5BA3\u8A00:");
		
		text_declaration = new Text(composite, SWT.BORDER);
		text_declaration.setEditable(false);
		text_declaration.setTouchEnabled(true);
		text_declaration.setBounds(101, 118, 169, 23);
		
		text_age = new Text(composite, SWT.BORDER);
		text_age.setEditable(false);
		text_age.setBounds(101, 80, 73, 23);
		
		text_name = new Text(composite, SWT.BORDER);
		text_name.setEditable(false);
		text_name.setText("");
		text_name.setBounds(101, 39, 73, 23);
		
		label_picture = new Label(composite, SWT.NONE);
		label_picture.setImage(null);
		label_picture.setBounds(191, 25, 79, 73);
		
		Button button_sure = new Button(shell, SWT.NONE);
		button_sure.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				int vote_id = getCandidate_id();
				if(vote_id == -1) {
					JOptionPane.showMessageDialog(null, "注意", "请选择候选人", JOptionPane.INFORMATION_MESSAGE); 
				}else{
					shell.close();
				}
			}
		});
		button_sure.setBounds(253, 316, 80, 27);
		button_sure.setText("\u786E\u5B9A");
		
		Button button_cancle = new Button(shell, SWT.NONE);
		button_cancle.setText("\u53D6\u6D88");
		button_cancle.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				setCandidate_id(-1);
				shell.close();
			}
		});
		button_cancle.setBounds(390, 316, 80, 27);
		
		
		list = Dao.getCandidateInfo();
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

	public int getCandidate_id() {
		return Candidate_id;
	}

	private void setCandidate_id(int candidate_id) {
		Candidate_id = candidate_id;
	}
}
