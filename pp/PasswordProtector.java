/*
 * Decompiled with CFR 0_122.
 *
 * Decompile the .class files to .java
 * java -jar cfr_0_122.jar pp.jar --outputdir ./pp 
 *
 * The answer is at http://www.hacker.org/challenge/misc/pwprot.php -> pwnasoreass
 */
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.LayoutManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.Reader;
import java.net.URL;
import javax.swing.JApplet;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

public class PasswordProtector
extends JApplet {
    String dir;
    int width;

    private void createGUI() {
        this.width = this.getSize().width;
        Container cp = this.getContentPane();
        JPanel panel = new JPanel(new FlowLayout());
        cp.add((Component)panel, "Center");
        panel.add(new JLabel("Password:"));
        final JTextField pw = new JTextField(12);
        panel.add(pw);
        JButton go = new JButton("Check It");
        panel.add(go);
        go.addActionListener(new ActionListener(){

            public void actionPerformed(ActionEvent ev) {
                try {
                    URL u = new URL("http://www.hacker.org/challenge/misc/pwprot.php");
                    BufferedReader in = new BufferedReader(new InputStreamReader(u.openStream()));
                    String line = in.readLine();
                    if (line.equals(pw.getText())) {
                        JOptionPane.showMessageDialog(PasswordProtector.this, "correct");
                    } else {
                        JOptionPane.showMessageDialog(PasswordProtector.this, "wrong");
                    }
                }
                catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public void init() {
        try {
            SwingUtilities.invokeAndWait(new Runnable(){

                public void run() {
                    PasswordProtector.this.createGUI();
                }
            });
        }
        catch (Exception e) {
            System.err.println("createGUI didn't successfully complete");
        }
    }

    public void start() {
    }

    public void stop() {
    }

}

