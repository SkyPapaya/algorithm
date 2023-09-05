package project3.function;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class InterFace extends JFrame implements ActiveEvent{
    Bank bank;
    User user;
    private boolean judgement = true;

    Box login, box1, box2;

   public void  createLogin() {
        box1 = Box.createVerticalBox();
        box1.add(new JLabel("UserName"));
        box1.add(Box.createVerticalStrut(8));
        box1.add(new JLabel("PassWord"));
        box1.add(Box.createVerticalStrut(8));
        box2 = Box.createVerticalBox();
        box2.add(new JTextField(20));
        box2.add(Box.createVerticalStrut(8));
        box2.add(new JTextField(20));
        box2.add(Box.createVerticalStrut(8));
        login = Box.createHorizontalBox();
        login.add(box1);
        login.add(Box.createVerticalStrut(8));
        login.add(box2);
        setLayout(new FlowLayout());
        add(login);
        validate();
        Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
        setBounds((dimension.width - 300) / 2, (dimension.height - 150) / 2, 300, 150);
       // actionPerformed();
        setVisible(judgement);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void actionPerformed(ActionEvent e){
        JTextField textSource =  (JTextField)e.getSource();
        if(user.getUsername() == 123456 && user.getPassword() == 88888888){
            judgement = false;
        }
    }
    public void createATM(){
       JMenuBar menuBar = new JMenuBar();
       JMenu menu = new JMenu("");
    }


}
