/*
 * Decompiled with CFR 0_122.
 *
 * java -jar cfr_0_122.jar pp0.jar --outputdir ./pp0
 * and the answer after viewing the source code, is 771772773
 */
package hacker.chal.prot;

import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.LayoutManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.PrintStream;
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
                    String s = Integer.toString(771772773);
                    if (s.equals(pw.getText())) {
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

