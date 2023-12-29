interface UserDetails {
  name: string;
  age: number;
  email: string;
}

interface Prototype {
  clone(): Prototype;
  getUserDetails(): UserDetails;
}

class ConcretePrototype implements Prototype {
  private user: UserDetails;
  constructor(user: UserDetails) {
    this.user = user;
  }

  clone() {
    const clone = Object.create(this);
    clone.user = { ...this.user };
    return clone;
  }

  getUserDetails(): UserDetails {
    return this.user;
  }
}

// client code
const p1 = new ConcretePrototype({
  name: "John",
  age: 30,
  email: "john@example.com",
});
const p2 = p1.clone();

if (p1.getUserDetails() === p2.getUserDetails()) {
  console.log("Cloned objects are the same instance.");
} else {
  console.log("Cloned objects are not the same instance.");
}
