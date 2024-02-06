# password-utils

password-utils is a module for the [Dictu](https://github.com/) programming language that supports creating, checking, salting passwords, etc.

## Example

```cs
const passLen = 14
const pass = Password();
pass.generate(passLen, true);
const password = pass.get();

print("Password : {}".format(password));
print("SHA256   : {}".format(pass.sha256().unwrap()));
print("bcrypt   : {}".format(pass.bcrypt().unwrap()));

pass.isSecure().match(
    def(result) => {
        print("secure  : yes");
        return;
    },
    def(error) => {
        print(error);
    }
);

print("Salt: {}".format(pass.salt()));
```

## Contact

Brian Downs [@bdowns328](http://twitter.com/bdowns328)

## License

password-utils source code is available under the BSD 3 Clause [License](/LICENSE).
