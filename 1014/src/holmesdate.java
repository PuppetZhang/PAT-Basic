import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class holmesdate {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in); // Scanner类
		BufferedReader strin=new BufferedReader(new InputStreamReader(System.in));  
		String[] str = new String[4];
		int week = 0, hour = 0, minute = 0;
		int[] len = new int[4];
//		while (true){
//			try {
//				char i = (char) System.in.read();
//			} catch (IOException e) {
//				// TODO Auto-generated catch block
//				e.printStackTrace();
//			}
//			
//		}
//		
		for (int i = 0; i < 4; i++) {
			str[i] = in.next();
			len[i] = str[i].length();
		}
		in.close();
		// determine week
		int i = 0;
		for (; i < (len[0] > len[1] ? len[1] : len[0]); i++) {
			if (str[0].substring(i, i + 1).indexOf(str[1].substring(i, i + 1)) != -1) {
				char[] temp = str[0].substring(i, i + 1).toCharArray();
				if (temp[0] <= 'Z' && temp[0] >= 'A') {
					week = temp[0] - 'A' + 1;
					break;
				}
			}
		}
		switch (week) {
		case 1:
			System.out.print("MON ");
			break;
		case 2:
			System.out.print("TUE ");
			break;
		case 3:
			System.out.print("WED ");
			break;
		case 4:
			System.out.print("THU ");
			break;
		case 5:
			System.out.print("FRI ");
			break;
		case 6:
			System.out.print("SAT ");
			break;
		case 7:
			System.out.print("SUN ");
			break;
		default:
			System.out.println("Week Err");
			break;
		}

		// determine hour
		for (i = i + 1; i < (len[0] > len[1] ? len[1] : len[0]); i++) {
			if (str[0].substring(i, i + 1).indexOf(str[1].substring(i, i + 1)) != -1) {
				char[] temp = str[0].substring(i, i + 1).toCharArray();
				if (temp[0] <= '9' && temp[0] >= '0')
					hour = temp[0] - '0';
				else if (temp[0] <= 'N' && temp[0] >= 'A')
					hour = temp[0] - 'A' + 10;
				else
					System.out.print("Err");
				break;
			}
		}
		if (hour <= 9)
			System.out.print('0');
		System.out.print(hour);
		System.out.print(':');
		// determine minute
		for (i = 0; i < (len[2] > len[3] ? len[3] : len[2]); i++) {
			if (str[2].substring(i, i + 1).indexOf(str[3].substring(i, i + 1)) != -1) {
				char[] temp = str[2].substring(i, i + 1).toCharArray();
				if (temp[0] <= 'z' && temp[0] >= 'a') {
					minute = i;
					break;
				}
			}
		}
		if (minute <= 9)
			System.out.print('0');
		System.out.println(minute);
		
	}
}
