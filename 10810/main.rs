use std::io;

fn main() {
    let mut s = String::new();

    io::stdin().read_line(&mut s).unwrap();

    let mut input = s.trim().split_whitespace();

    let n: i32 = input.next().unwrap().parse().unwrap();
    let m: i32 = input.next().unwrap().parse().unwrap();
    let mut ans: [i32; 101] = [0; 101];

    for _ in 0..m {
        let mut ss = String::new();
        io::stdin().read_line(&mut ss).unwrap();
        input = ss.trim().split_whitespace();

        let a: i32 = input.next().unwrap().parse().unwrap();
        let b: i32 = input.next().unwrap().parse().unwrap();
        let c: i32 = input.next().unwrap().parse().unwrap();
        
        for i in a..b+1 {
            ans[i as usize] = c;
        }
    }
    
    for i in 1..n+1 {
        print!("{} ", ans[i as usize]);
    }
}