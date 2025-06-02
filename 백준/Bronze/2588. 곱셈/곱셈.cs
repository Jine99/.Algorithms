class Program
{
    static void Main(string[] args)
    {

        string input1 = Console.ReadLine();
        string input2 = Console.ReadLine();

        int input3 = int.Parse(input2);

        int A = input3 % 10;
        input3 = input3 / 10;
        int B = input3 % 10;
        input3 = input3 / 10;
        int C = input3 % 10;

        int D = int.Parse(input1) * A;
        int E = int.Parse(input1) * B;
        int F = int.Parse(input1) * C;

        Console.WriteLine(D);
        Console.WriteLine(E);
        Console.WriteLine(F);
        Console.WriteLine(D+(E*10)+(F*100));
    }   
}
