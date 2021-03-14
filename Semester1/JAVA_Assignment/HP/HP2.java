import javax.swing.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class HP2 {
    public static void main(String[] args) {
        UIDriver uiDriver = new UIDriver();
        uiDriver.createView();
    }
}

class UIDriver {
    SimpleDateFormat formatter = new SimpleDateFormat("dd-MMM-yyyy");

    void createView() {
        JFrame frame = new JFrame("HP2");

        JLabel label1, label2, label3;
        JTextField textField1, textField2;

        label1 = new JLabel("Name");
        textField1 = new JTextField("Enter your name.");
        label1.setBounds(10, 50, 60, 30);
        textField1.setBounds(100, 50, 200, 30);
        frame.add(label1);
        frame.add(textField1);

        label2 = new JLabel("Date of Joining");
        label2.setBounds(10, 100, 90, 30);
        frame.add(label2);

        String[] day = {
                "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
        JComboBox<String> comboBoxDay = new JComboBox<>(day);
        comboBoxDay.setBounds(100, 100, 50, 30);
        frame.add(comboBoxDay);

        String[] month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        JComboBox<String> comboBoxMonth = new JComboBox<>(month);
        comboBoxMonth.setBounds(160, 100, 60, 30);
        frame.add(comboBoxMonth);

        String[] year = new String[101];
        for (int i = 0; i <= 100; i++) {
            year[i] = String.valueOf(2000 + i);
        }
        JComboBox<String> comboBoxYear = new JComboBox<>(year);
        comboBoxYear.setBounds(230, 100, 100, 30);
        frame.add(comboBoxYear);

        label3 = new JLabel("Address");
        textField2 = new JTextField("Enter your address.");
        label3.setBounds(10, 150, 60, 30);
        textField2.setBounds(100, 150, 200, 30);
        frame.add(label3);
        frame.add(textField2);

        JButton display = new JButton("Display");
        display.setBounds(50, 200, 100, 50);
        display.addActionListener(e -> {
            Date date = null;
            String S = (comboBoxDay.getSelectedItem() + "-" + comboBoxMonth.getSelectedItem() + "-" + comboBoxYear.getSelectedItem());
            try {
                date = formatter.parse(S);
            } catch (ParseException parseException) {
                parseException.printStackTrace();
            }
            dataView(textField1.getText(), textField2.getText(), date);

        });
        frame.add(display);

        JButton cancel = new JButton("Clear");
        cancel.setBounds(160, 200, 100, 50);
        cancel.addActionListener(e -> {
            frame.dispose();
            createView();
        });
        frame.add(cancel);

        frame.setSize(350, 300);
        frame.setLayout(null);
        frame.setVisible(true);
    }

    void dataView(String Name, String Address, Date date) {
        JFrame frame = new JFrame("Data");

        JLabel label1, label2, label3, label1Data, label2Data, label3Data;

        label1 = new JLabel("Name");
        label1.setBounds(10, 10, 60, 30);
        frame.add(label1);
        label1Data = new JLabel(Name);
        label1Data.setBounds(80, 10, 200, 30);
        frame.add(label1Data);

        label2 = new JLabel("Date");
        label2.setBounds(10, 30, 60, 30);
        frame.add(label2);
        label2Data = new JLabel(formatter.format(date));
        label2Data.setBounds(80, 30, 200, 30);
        frame.add(label2Data);

        label3 = new JLabel("Address");
        label3.setBounds(10, 50, 60, 30);
        frame.add(label3);
        label3Data = new JLabel(Address);
        label3Data.setBounds(80, 50, 200, 30);
        frame.add(label3Data);

        frame.setSize(350, 125);
        frame.setLayout(null);
        frame.setVisible(true);
    }
}