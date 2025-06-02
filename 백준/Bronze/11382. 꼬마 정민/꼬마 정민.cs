class Program
{
    static void Main(string[] args)
    {

        string input1 =Console.ReadLine();
        string[] input = input1.Split();

        Console.Write(long.Parse(input[0].ToString()) + long.Parse(input[1].ToString()) + long.Parse(input[2].ToString()));
        
    }   
}
