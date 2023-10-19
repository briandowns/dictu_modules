# dson

dson is a Dictu module for JSON serialization and deserialization focusing its functionality around classes.

## API

### parse(data, klass) -> Result

parse receives a JSON encoded string and a class to deserialize the data to.


### stringfy(klass) -> String

stringify receives a class and resturns a JSON string with the contents of the class. Only public fields are taken into consideration.


## Contact

Brian Downs [@bdowns328](http://twitter.com/bdowns328)


## License

dson source code is available under the BSD 3 Clause [License](/LICENSE).
