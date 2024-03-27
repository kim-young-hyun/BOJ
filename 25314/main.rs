use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();

    let n: i32 = s.trim().parse().unwrap();
    let m = n / 4;

    for i in 0..m {
        print!("long ");
    }
    print!("int");
}
