using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Rextester
{
    public class Program
    {
        public static void task_2149()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            int size_str = 5*n-1;
            
            char[] str = new char[size_str];
            
            str = Console.ReadLine().ToCharArray();
            bool[] beaks = new bool[n];
            for(int i=0,j=0;i<str.Length;i++)
            {
                if(str[i] == 62)
                {
                    beaks[j] = true;
                    j++;
                }
                else if(str[i] == 60)
                {
                    beaks[j] = false;
                    j++;
                }
            }
            
            str = Console.ReadLine().ToCharArray();
            str = Console.ReadLine().ToCharArray();
            
            /*for(int i=0;i<n;i++)
            {
                Console.Write("{0} ",beaks[i]);
            }*/
            
            int min = n;
            int count1=0,count2=0;
            for(int i=0;i<2;i++)
            {
                count1 = count2 = 0;
                bool tmp = Convert.ToBoolean(i);
                for(int j=0;j<n;j++)
                {
                    if(j==n/2)
                    {
                        tmp = !tmp;
                    }
                    if(beaks[j] != tmp)
                    {
                        count1++;
                    }
                }
                
                tmp = !tmp;
                
                for(int j=0;j<n;j++)
                {
                    if((j+1)%2!=0)
                    {
                        if(beaks[j]!=tmp)
                        {
                            count2++;
                        }
                    }
                    else
                    {
                        if(beaks[j]!= !tmp)
                        {
                            count2++;
                        }
                    }
                }
		
                if(count1 < count2)
                {
                    if(count1<min)
                    {
                        min = count1;
                    }
                }
                else
                {
                    if(count2<min)
                    {
                        min = count2;
                    }
                }
            }
            Console.WriteLine("\n{0}",min);
        }
        
        public static void Main(string[] args)
        {
           task_2149();
        }
    }
}
