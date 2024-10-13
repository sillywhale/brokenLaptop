using System;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace labs
{
    internal class Program
    {
        public static void firstFunc()
        {
            bool isCorrect = false;
            int n = 0, m = 0;
            double x = 0;

            Console.WriteLine("Ввпдите целые числа для n, m, дробное для x\n");
            while (!isCorrect)
            {
                if ((int.TryParse(Console.ReadLine(), out n))
                    && (int.TryParse(Console.ReadLine(), out m) && m != 0)
                    && (double.TryParse(Console.ReadLine(), out x))
                    && (x != 0)
                    && (m != 1) )
                    isCorrect = true;
                else
                    Console.WriteLine("Ввпдите целые числа для n, m, дробное дляx\n");
            }

            int firstResult = (n++ / --m);
            firstResult++;
            System.Console.WriteLine("\n1: " + firstResult);

            bool secondResult = (++m < n--);
            System.Console.WriteLine("\n2: " + secondResult);

            bool thirdResult = (--m > ++n);
            System.Console.WriteLine("\n3: " + thirdResult);

            double fourthResult = Math.Pow((Math.Pow(Math.E, x) + Math.Tan(x)), 1 / 3) + 1 / x;
            System.Console.WriteLine("\n4: "+fourthResult);
        }

        public static void secondFunc()
        {
            Console.WriteLine("\nВведите числа с плавающей точкой, для координат точки");
            double x = 0, y = 0;
            bool isCorrect = false;
            while (!isCorrect)
            {
                if (double.TryParse(Console.ReadLine(), out x)
                    && double.TryParse(Console.ReadLine(), out y))
                    isCorrect = true;
                else Console.WriteLine("Введите числа с плавающей точкой");
            }

            if ( ((x > 0) && (Math.Sqrt(x * x+ y * y) <= 1 ))
                || ( (y > 0 && x < 0) && (Math.Sqrt(x * x + y * y) <= 1) )
                || ( ( x > -1) && ( y > -1) && (y < 1) && (x < 1) ) )
                    System.Console.WriteLine("Точка принадлежит выделенной плоскости");
            else System.Console.WriteLine("Точка не принадлежит заданной плоскости");
        }

        public static void thirdFunc()
        {
            float a = 1000f, b = 0.0001f;
            double c = 1000, d = 0.0001;

            float firstPart = (float)(Math.Pow(a + b, 4));
            float secondPart = (float)(Math.Pow(a,4)+6 * a * a * b * b+4 * a * b * b * b);
            float thirdPart = (float)(Math.Pow(b, 4) + 4 * a * a * a * b);

            double doubleFirstPart = Math.Pow(c + d, 4);
            double doubleScondPart = Math.Pow(c, 4) + 6 * c * c * d * d + 4 * c * d * d * d;
            double doubleThirdPart = Math.Pow(d, 4) + 4 * c * c * c * d;

            float firstResult = (float)((firstPart-secondPart)/thirdPart);
            double secondResult = (doubleFirstPart-doubleScondPart)/doubleThirdPart;

            System.Console.WriteLine($"\nFloat result {firstResult}\nDouble reuslt {secondResult}");
        }
        static void Main(string[] args) 
        {
            firstFunc();

            secondFunc();

            thirdFunc();
        }
    }
}
