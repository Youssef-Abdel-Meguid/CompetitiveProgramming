import java.*;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		String Verb = "(hate|love|know|like)s*";
		String Noun = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
		String Article = "(a|the)";
		String Actor = "(" + Noun + "|" + Article + " " + Noun + ")";
		String Active_List = "(" + Actor + " and )*" + Actor;
		String Action = Active_List + " " + Verb + " " + Active_List;
		String Statement = Action + "( , "+ Action + ")*";
		
		while(sc.hasNext())
		{
			String s = sc.nextLine();
			if(s.matches(Statement))
				System.out.println("YES I WILL");
			else
				System.out.println("NO I WON'T");
		}
	}

}
