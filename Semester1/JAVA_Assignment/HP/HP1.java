import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.border.EmptyBorder;

public class HP1 {
    public static void main(String[] args) {
        MessageBox ob = new MessageBox("Do you accept your faith?");
        ob.createView();
        System.out.println("Button Clicked: " + ob.getButtonClicked());
    }
}

class MessageBox extends JDialog implements ActionListener {
    String message, buttonClicked;
    JButton accept, close;

    MessageBox(String message) {
        this.message = message;
    }

    void createView() {
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);

        JDialog dialog = new JDialog(frame, "User Prompt", true);

        JPanel mainGui = new JPanel(new BorderLayout());
        mainGui.setBorder(new EmptyBorder(20, 20, 20, 20));
        mainGui.add(new JLabel(message), BorderLayout.CENTER);

        JPanel buttonPanel = new JPanel(new FlowLayout());
        mainGui.add(buttonPanel, BorderLayout.SOUTH);

        accept = new JButton("Accept");
        accept.addActionListener(e -> {
            dialog.setVisible(false);
            JOptionPane.showMessageDialog(
                    null,
                    "For that is our curse!",
                    "Suffer",
                    JOptionPane.INFORMATION_MESSAGE);
            buttonClicked = "accept";
        });

        close = new JButton("Close");
        close.addActionListener(e -> {
            dialog.setVisible(false);
            buttonClicked = "close";
        });

        buttonPanel.add(close);
        buttonPanel.add(accept);

        frame.setVisible(true);

        dialog.setContentPane(mainGui);
        dialog.pack();
        dialog.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
    }

    public String getButtonClicked() {
        return buttonClicked;
    }
}