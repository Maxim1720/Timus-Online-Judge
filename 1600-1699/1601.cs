using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Text;

namespace Rextester
{
    public class Program
    {
        public static void task_1601()
        {
            char[] str = new char[10000];
            
            str = Console.In.ReadToEnd().ToCharArray();
            
            int sentence_size = 0;
            
            for(int i=0;i<str.Length;i++)
            {
                if(str[i]>64 && str[i]<91)
                {
                    if(sentence_size>0)
                    {
                        str[i] += Convert.ToChar(32);
                    }
                    sentence_size++;
                }
                else if(str[i] == '.' || str[i] == '?' || str[i] == '!')
                {
                	sentence_size = 0;
                }
            }
            Console.WriteLine(str);
        }
        
        
        public static void Main(string[] args)
        {
            task_1601();
        }
    }
}
