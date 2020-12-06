using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Rextester
{
    public class User
    {
        char[] Name = new char[30];
        char[] Password = new char[30];
        bool Online = false;
        
        public User(char[] n, char[] p)
        {
            Name = n;
            Password = p;
        }    
        public void SetOnline()
        {
            Online = true;
        }
        public void SetOffline()
        {
            Online = false;
        }
        
        public bool GetOnline()
        {
            return Online;
        }
        
        public char[] GetName()
        {
            return Name;
        }
        public char[] GetPassWord()
        {
            return Password;
        }
        
    }
    public static class UsersBase
    {
        
        static List<User> users = new List<User>();
        
        static int count = 0;
        
        public static string Register(char[] name, char[] pass)
        {
         
            foreach(User u in users)
            {
                if(new string(u.GetName()).Equals(new string(name)))
                {
                    return "fail: user already exists";
                }
            }
            
            users.Add(new User(name,pass));
            return "success: new user added";
        }
        
        public static string Logout(char[] name)
        {
            foreach(User u in users)
            {
                if(new string(u.GetName()).Equals(new string(name)))
                {
                    if(u.GetOnline() == true)
                    {
                        u.SetOffline();
                        return "success: user logged out";
                    }
                    else
                    {
                        return "fail: already logged out";
                    }
                }
                
            }
            return "fail: no such user";
        }
        
        public static string Login(char[] name, char[] pass)
        {
            foreach(User u in users)
            {
                if(string.Equals(new string(u.GetName()), new string(name)))
                {
                    if(string.Equals(new string(pass),new string(u.GetPassWord())))
                    {
                        if(u.GetOnline() == false)
                        {
                            u.SetOnline();
                            return "success: user logged in";
                        }
                        else
                        {
                            return "fail: already logged in";
                        }
                    }
                    else
                    {
                        return "fail: incorrect password";
                    }
                }
                
            }
            return "fail: no such user";
        }
            
        
        
        
    }
    
    public class Program
    {
        public static void task_2002()
        {
            int n;
            n = Convert.ToInt32(Console.ReadLine());
            
            string[] actions = {"register","login","logout"};
            
            string[] strs = new string[n];
            for(int i=0;i<n;i++)
            {
                strs[i] = Console.ReadLine();
                
            }
            
            
            for(int i=0;i<n;i++)
            {
                string[] tmp = strs[i].Split(' ');
                
                if(tmp[0].Equals(actions[0]))
                {
                    Console.WriteLine(UsersBase.Register(tmp[1].ToCharArray(),tmp[2].ToCharArray()));
                }
                else if(tmp[0].Equals(actions[1]))
                {
                    Console.WriteLine(UsersBase.Login(tmp[1].ToCharArray(),tmp[2].ToCharArray()));
                }
                else if(tmp[0].Equals(actions[2]))
                {
                    Console.WriteLine(UsersBase.Logout(tmp[1].ToCharArray()));
                }
                
                
            }
            
        }
        
        public static void Main(string[] args)
        {
            task_2002();
        }
    }
}
