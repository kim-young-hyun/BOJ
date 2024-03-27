use std::io;

fn main() {
    let mut s = String::new();

    io::stdin().read_line(&mut s).unwrap();

    let mut input = s.trim().split_whitespace();

    let n: i32 = input.next().unwrap().parse().unwrap();
    let m: i32 = input.next().unwrap().parse().unwrap();

    let mut arr: [i32; 101] = [0; 101];
    for i in 1..n+1 {
        arr[i as usize] = i;
    }

    for _ in 0..m {
        s = String::new();
        io::stdin().read_line(&mut s).unwrap();

        input = s.trim().split_whitespace();

        let a: usize = input.next().unwrap().parse().unwrap();
        let b: usize = input.next().unwrap().parse().unwrap();

        arr.swap(a, b);
    }

    for i in 1..n+1 {
        print!("{} ", arr[i as usize]);
    }
}