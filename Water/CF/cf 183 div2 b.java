import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.TimeZone;

public class a{
 public static long getQuot(String time1, String time2){
  long quot = 0;
  SimpleDateFormat ft = new SimpleDateFormat("yyyy:MM:dd");
  ft.setTimeZone(TimeZone.getTimeZone("UTC"));
  try {
   Date date1 = ft.parse( time1 );
   Date date2 = ft.parse( time2 );
   quot = date1.getTime() - date2.getTime();
   quot = quot / (1000 * 60 * 60 * 24);
  } catch (ParseException e) {
   e.printStackTrace();
  }
  return quot;
 }
 public static void main(String[] args) throws Exception {
	Scanner r = new Scanner(System.in);
  String date1 = r.nextLine();
  String date2 = r.nextLine();
  long day = getQuot(date2,date1);
  System.out.println(Math.abs(day));
 }
}