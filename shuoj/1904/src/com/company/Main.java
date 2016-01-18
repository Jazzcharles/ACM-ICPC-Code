package com.company;

import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
         Scanner in=new Scanner(System.in);
         int n=in.nextInt();
         if(n==1)
            System.out.println("Accepted");
         else if(n==2)
            System.out.println("Wrong Answer");
         else
            System.out.println("handsome yaoge");
    }
}
