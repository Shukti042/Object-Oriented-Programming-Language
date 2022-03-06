import java.util.*;
import java.io.*;
public class Car {
    public String RegNo;
    public int YearMade;
    public String Colour1;
    public String Colour2;
    public String Colour3;
    public String CarMake;
    public String CarModel;
    public int Price;
    public static ArrayList<Car> carlist = new ArrayList<Car>(5);
    public static int item=0;
    public String strDet;//the string form of the car details
    public Car(String inp) {
        String[] out = inp.split(",");
        RegNo = out[0];
        YearMade = Integer.parseInt(out[1]);
        Colour1 = out[2];
        Colour2 = out[3];
        Colour3 = out[4];
        CarMake = out[5];
        CarModel = out[6];
        Price = Integer.parseInt(out[7]);
        strDet=inp;
    }
    public void Display()
    {
        System.out.println(strDet);
    }

    public static void  Add(String inputs) throws IOException
    {
        String[] out=inputs.split(",");
        boolean b=true;
        BufferedReader br=new BufferedReader(new FileReader("car.txt"));
        while (true)
        {
            String line=br.readLine();
            if(line==null)
            {
                break;
            }
            else
            {
                String [] l=line.split(",");
                if(l[0].equalsIgnoreCase(out[0]))
                {
                    b=false;
                    System.out.println("This Registration Number Already Exists");
                    break;
                }
            }

        }
        br.close();
        if(b)
        {
            BufferedWriter bw=new BufferedWriter(new FileWriter("car.txt",true));
            bw.append(inputs+"\n");
            bw.close();
            carlist.add(new Car(inputs));
            item++;
        }

    }
    public static void Delete(String reg) throws IOException
    {
        boolean t=true;
        for (int i=0;i<carlist.size();i++)
        {
            if(carlist.get(i).RegNo.equalsIgnoreCase(reg))
            {
                carlist.remove(i);
                item--;
                t=false;
            }
        }
        PrintWriter writer = new PrintWriter("car.txt");
        writer.print("");
        writer.close();
        BufferedWriter bw=new BufferedWriter(new FileWriter("car.txt",true));
        for (int i=0;i<carlist.size();i++)
        {
            bw.append(carlist.get(i).strDet+"\n");
        }
        bw.close();
        if(t)
        {
            System.out.println("No Car of this Registratin number Exists");
        }




    }
    public static void SearchRegNo(String in)
    {
        boolean b=true;
        for (int i=0;i<carlist.size();i++)
        {
            if(in.equalsIgnoreCase(carlist.get(i).RegNo))
            {
                carlist.get(i).Display();
                b=false;
            }
        }
        if(b)
        {
            System.out.println("No such car with this Registration Number");
        }
    }

    public static void SearchCarmakeModel(String camake,String camodel)
    {
        boolean b=true;
        for (int i=0;i<carlist.size();i++)
        {
            if((camake.equalsIgnoreCase(carlist.get(i).CarMake))&&((camodel.equalsIgnoreCase(carlist.get(i).CarModel))||camodel.equalsIgnoreCase("ANY")))
            {
                carlist.get(i).Display();
                b=false;
            }
        }
        if(b)
        {
            System.out.println("No such car with this Car Make and Car Model");
        }
    }

   public static void main(String[] args) throws IOException {
       try (BufferedReader br = new BufferedReader(new FileReader("car.txt"))) {
           while (true) {
               String lin = br.readLine();
               if (lin == null) {
                   break;
               } else {
                   carlist.add(new Car(lin));
                   item++;
               }
           }
       }catch (Exception e)
       {
           e.printStackTrace();
       }

       Scanner sc = new Scanner(System.in);
       while (true)
       {
           System.out.println("(1) Search Cars\n(2) Add Car\n(3) Delete Car\n(4) Exit System");
           int a=sc.nextInt();
           sc.nextLine();
           switch (a)
           {
               case 1:
                   while (true)
                   {
                       System.out.println("(1) By Registration Number\n(2) By Car Make and Car Model\n(3) Back to Main Menu");
                       int b=sc.nextInt();
                       sc.nextLine();
                       switch (b)
                       {
                           case 1:
                               System.out.println("Enter The Registration Number:");
                               String treg=sc.nextLine();
                               Car.SearchRegNo(treg);
                               break;
                           case 2:
                               System.out.println("Enter The Car Make");
                               String tcmak=sc.nextLine();
                               System.out.println("Enter The Car Model");
                               String tcmod=sc.nextLine();
                               Car.SearchCarmakeModel(tcmak,tcmod);
                               break;
                           case 3:
                               break;
                               default:
                                   System.out.println("Error Serial No");



                       }
                       if(b==3)
                       {
                           break;
                       }
                   }
                   break;
               case 2:
                   System.out.println("Enter the car details:");
                   String tempcar=sc.nextLine();
                   Car.Add(tempcar);
                   break;
               case 3:
                   System.out.println("Enter the Reg No of the car to be deleted:");
                   String dcar=sc.nextLine();
                   Car.Delete(dcar);
                   break;
               case 4:
                   break;
                   default:
                       System.out.println("Error Serial No");

           }
           if(a==4)
           {
               break;
           }
       }



    }
}



