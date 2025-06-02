using System;

class Program

{

    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');

        Console.WriteLine(int.Parse(input[0].ToString()) + int.Parse(input[1].ToString()));
    }
}