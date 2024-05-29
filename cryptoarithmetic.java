package PracticeAlLabExam;

import java.util.HashMap;

public class cryptoarithmetic {
    public static int getNumber(String s,HashMap<Character,Integer> hm)
    {
        /*This method converts a string of characters into an integer based on the mapping provided by the hashmap hm. It iterates through each character in the input string s, retrieves its corresponding integer value from the hashmap hm, concatenates these values to form a string num, and finally parses num into an integer and returns it. */
        String num="";
        for(int i=0;i<s.length();i++)
        {
            num+=hm.get(s.charAt(i));
        }
        return Integer.parseInt(num);
    }
    public static void solve(int i,String unique,boolean used[],HashMap<Character,Integer> hm,String words[],String result)
    {
        /*This is a recursive method to solve the cryptarithmetic puzzle. It takes several parameters:
i: The current index in the unique character string.
unique: A string containing all unique characters from the words and the result.
hm: A hashmap containing the mapping of characters to integers.
used: A boolean array indicating which digits have been used.
words: An array of strings representing the words in the puzzle equation.
result: A string representing the result of the equation.
Inside the method, it checks if i has reached the end of the unique character string. If so, it calculates the sum of the numbers represented by the words and compares it to the number represented by the result. If they are equal, it prints the mapping of characters to digits. Then, it recursively calls itself, trying different digit mappings for the remaining characters.

 */
        if(i==unique.length())
        {
            int sum=0;
            for(String s:words)
            {
                sum+=getNumber(s,hm);
            }
            int r=getNumber(result,hm);

            if(sum==r)
            {
                for(int k=0;k<=25;k++)
                {
                    char ch=(char)('A'+k);
                    if(hm.containsKey(ch))
                    {
                        System.out.print(ch+"-->"+hm.get(ch)+" ");
                    }
                }
                System.out.println();
            }
            return;
        }
        char ch=unique.charAt(i);
        for(int j=0;j<=9;j++)
        {
            if(!used[j])
            {
                hm.put(ch, j);
                used[j]=true;
                solve(i+1, unique,used, hm, words, result);
                hm.put(ch, -1);
                used[j]=false;
            }
        }

    }
    public static void main(String[] args) {
        // Initializes the puzzle by defining the words (SEND, MORE) and the result (MONEY).
// Creates a hashmap (hm) to store the mappings of characters to digits.
// Creates a string (unique) to store all unique characters from the words and the result.
// Iterates through each character in the words and the result, adding them to the hashmap if they are not already present and adding them to the unique string.
// Initializes a boolean array (used) to keep track of which digits have been used.
// Calls the solve method with the initial parameters to solve the puzzle.
        String words[]={"SEND","MORE"};
        String result="MONEY";
        String unique="";

        HashMap<Character,Integer> hm=new HashMap<>();
        for(String s:words)
        {
            for(int i=0;i<s.length();i++)
            {
                char ch=s.charAt(i);
                if(!hm.containsKey(ch))
                {
                    hm.put(ch, -1);
                    unique+=ch;
                }
            }
        }
        for(int i=0;i<result.length();i++)
        {
            char ch=result.charAt(i);
            if(!hm.containsKey(ch))
            {
                hm.put(ch, -1);
                unique+=ch;
            }
        }
        boolean used[]=new boolean[10];
        solve(0,unique,used,hm,words,result);
    }
}
