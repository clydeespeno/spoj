package com.jce.spoj;

import java.util.Scanner;

public class Test {

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int tests = Integer.parseInt(scanner.nextLine());
        for(String sol = scanner.nextLine(); tests > 0 && life(sol); tests--,sol = scanner.nextLine());

    }

    public static boolean life(String sol) {
        if(!sol.equals("42")) {
            System.out.println(sol);
            return true;
        }
        return false;
    }

}
