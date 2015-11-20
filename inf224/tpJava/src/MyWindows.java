import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


public class MyWindows extends JFrame{
	private static final long serialVersionUID = 1L;
	//JButton button1, button2, button3;
	private JTextArea text;
	private JPanel panel= new JPanel();
	private JScrollPane scroll= new JScrollPane();
	private JTextField bartext = new JTextField("Insert the name of the multimedia object", 10);
	private JMenuBar menubar = new JMenuBar();
	private JMenu menu1 = new JMenu("Commands");
	private JToolBar tool = new JToolBar("bar");
	private Search search = new Search("Search");
	private DeleteObj deleteobj = new DeleteObj("Delete Multimedia Object");
	private DeleteGroup deletegroup = new DeleteGroup("Delete Group");
	private Play play = new Play("Play");
	private Print print = new Print("Print");
	private String command = "";
	//private String name = "";
	
/*	public static void main(String argv[]){
		new MyWindows();
	}
*/
	
	public MyWindows(){
		menubar.add(bartext);
		menubar.add(menu1);
/*		JMenuItem demarrer = new JMenuItem("Démarrer");
		JMenuItem fin = new JMenuItem("Fin");
		JMenuItem annuler = new JMenuItem("Annuler");
		JMenuItem copier = new JMenuItem("Copier");
		JMenuItem coller = new JMenuItem("Coller");
		menu1.add(demarrer);
		menu1.add(fin);
		menu1.add(annuler);
		menu1.add(copier);
		menu1.add(coller);*/
		
		
		JMenuItem searchb = new JMenuItem(search);
		JMenuItem delete1 = new JMenuItem(deleteobj);
		JMenuItem delete2 = new JMenuItem(deletegroup);
		JMenuItem _play = new JMenuItem(play);
		JMenuItem _print = new JMenuItem(print);
		menu1.add(_play);
		menu1.add(searchb);
		menu1.add(delete1);
		menu1.add(delete2);
		menu1.add(_print);
		setPreferredSize(new Dimension(600,300));
		BorderLayout border = new BorderLayout();
		add(tool, border.NORTH);
		tool.add(play);
		//tool.add(button1 = new JButton("Hey!"), border.NORTH);
		//menubar.add(button2 = new JButton("I am a JFrame!"), border.SOUTH);
		//add(button3 = new JButton("EXIT"),border.EAST);
		add(text = new JTextArea(20, 100));
		add(scroll);
		
		add(menubar, border.SOUTH);
		scroll.setPreferredSize(new java.awt.Dimension(10, 10));
		scroll.setViewportView(text);
		
		//setJMenuBar(menubar);
		
		//button1.addActionListener(new Button1Listener());
		//button2.addActionListener(new Button2Listener());
		//button3.addActionListener(new Button3Listener());
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		pack();
		setVisible(true);
	}
	
	public void setTextArea(String response){
		text.append(response + "\n");
	}
	
	public String getCommand(){
		return command;
	}
	
	public void setCommand(String s){
		command = s;
	}
		
/*	
 * 
	class Button1Listener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			text.append("Hey!\n");
		}
	}
	
	class Button2Listener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			text.append("I am a JFrame\n");
		}
	}
	
	class Button3Listener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			System.exit(0);
		}
	}*/
	
	class Search extends AbstractAction {
	    Search(String name){
	    	super(name);	    	
	    }
		public void actionPerformed(ActionEvent e) {			
	        if (bartext.getText().equals("") || bartext.getText().equals("Insert the name of the multimedia object")){	        		
	        	text.append("To use this command, please, enter the name of the multimedia object\n");
	        }
	        else{
	        	command = "search object|" + bartext.getText();
	        	bartext.setText("");
	        }
	    }
	}
	
	class DeleteObj extends AbstractAction {
	    DeleteObj(String name){
	    	super(name);	    	
	    }
		public void actionPerformed(ActionEvent e) {
			if (bartext.getText().equals("") || bartext.getText().equals("Insert the name of the multimedia object")){	        		
	        	text.append("To use this command, please, enter the name of the multimedia object\n");
	        }
	        else{
	        	command = "delete object|" + bartext.getText();
	        	bartext.setText("");
	        }
	    }
	}
	
	
	class DeleteGroup extends AbstractAction {
	    DeleteGroup(String name){
	    	super(name);	    	
	    }
		public void actionPerformed(ActionEvent e) {
			if (bartext.getText().equals("") || bartext.getText().equals("Insert the name of the multimedia object")){	        		
	        	text.append("To use this command, please, enter the name of the multimedia object\n");
	        }
	        else{
	        	command = "delete group|" + bartext.getText();
	        	bartext.setText("");
	        }
	    }
	}
	
	class Play extends AbstractAction {
	    Play(String name){
	    	super(name);	    	
	    }
		public void actionPerformed(ActionEvent e) {
			if (bartext.getText().equals("") || bartext.getText().equals("Insert the name of the multimedia object")){	        		
	        	text.append("To use this command, please, enter the name of the multimedia object\n");
	        }
	        else{
	        	command = "play|" + bartext.getText();
	        	bartext.setText("");
	        }
	    }
	}
	
	class Print extends AbstractAction {
	    Print(String name){
	    	super(name);	    	
	    }
		public void actionPerformed(ActionEvent e) {
			if (bartext.getText().equals("") || bartext.getText().equals("Insert the name of the multimedia object")){	        		
	        	text.append("To use this command, please, enter the name of the multimedia object\n");
	        }
	        else{
	        	command = "print object|" + bartext.getText();
	        	bartext.setText("");
	        }
	    }
	}
	
}

