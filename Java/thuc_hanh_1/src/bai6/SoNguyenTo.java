/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai6;
import java.util.*;

/**
 *
 * @author Bugs
 */
public class SoNguyenTo {
    public int n;
    
    public SoNguyenTo(int n){
        this.n = n;
    }
    
    public List<Integer> tim_so_nguyen_to(List<Integer> array_n, int max){
        boolean[] isPrime = new boolean[max + 1];
//        List<Integer> array_n = new ArrayList<>();
        for (int i = 2; i <= max; i++) {
            isPrime[i] = true;
            
        }

        for (int i = 2; i * i <= max; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= max; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= max; i++) {
            boolean  check = array_n.contains(i);
            if (isPrime[i] && check) {
                primes.add(i);
            }
        }
        return primes;  
    }
    
    
}
