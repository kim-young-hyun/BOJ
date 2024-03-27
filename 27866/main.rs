use std::io;

fn main() {
    let mut s = String::new();
    let mut input = String::new();
    io::stdin().read_line(&mut s).unwrap();
    io::stdin().read_line(&mut input).unwrap();
    let idx: i32 = input.trim().split_whitespace().next().unwrap().parse().unwrap();

    print!("{}", (s.as_bytes()[(idx - 1) as usize] as u8) as char);
}