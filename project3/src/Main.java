import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

//class FirstWindow extends JFrame {
//    JMenuBar menubar;
//    JMenu menu1,menu2;
//    JMenuItem item1, item2;
//
//    FirstWindow(String s) {
//        setTitle(s);
//        setSize(160, 170);
//        setLocation(120, 120);
//        setVisible(true);
//        menubar = new JMenuBar();
//        menu1 = new JMenu("文件");
//        menu2 = new JMenu("菜单");
//        menubar.add(menu1);
//        menubar.add(menu2);
//        //菜单项的文字是打开，并且附加图片
//        item1 = new JMenuItem("打开");
//        item2 = new JMenuItem("保存");
//        //设置快捷键
//        item1.setAccelerator(KeyStroke.getKeyStroke("o"));
//        item2.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, InputEvent.CTRL_MASK));
//        menu1.add(item1);
//        menu1.addSeparator();
//        menu1.add(item2);
//
//        setJMenuBar(menubar);
//        validate();
//        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//
//    }
class PoliceWindow extends JFrame implements ActionListener {
    JTextField titleText;
    JPasswordField passwordText;

    PoliceWindow() {
        titleText = new JTextField(10);
        passwordText = new JPasswordField(10);
        //设置隐藏密码的字符
        passwordText.setEchoChar('*');
        titleText.addActionListener(this);
        passwordText.addActionListener(this);
        setLayout(new FlowLayout());
        add(titleText);
        add(passwordText);
        setBounds(100, 100, 300, 300);
        setVisible(true);
        //使生效
        validate();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
//接口回调
    public void actionPerformed(ActionEvent e) {
        JTextField textSource = (JTextField) e.getSource();
        if (textSource == titleText) {
            this.setTitle(titleText.getText());
        } else if (textSource == passwordText) {
            char[] c = passwordText.getPassword();
            titleText.setText(new String(c));
        }
    }

}