fn main() {

    println!("\n-- Imutable Vector --");
    imutable_vector();

    println!("\n-- Mutable Vector --");
    mutable_vector();

}

fn imutable_vector() {
    
    /* Array: An imutable vector */

    let array: [i32; 7] = [1, 1, 2, 3, 5, 8, 13];

    println!("Value of indice 0: {}", array[0]);

    /* Impossible operation, because is imutable */
    // array[0] = 42;

}

fn mutable_vector() {

    /* List: An mutable vector */

    let mut list: [i32; 7] = [1, 1, 2, 3, 5, 8, 13];

    println!("Value of indice 0: {}", list[0]);

    /* Possible operation, because is mutable */
    list[0] = 42;

    println!("Value of indice 0: {}\n", list[0]);

}