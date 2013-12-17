template <typename T>
std::string toString(const T& value) {
	std::stringstream sstream;
	sstream << value;
	return sstream.str();
}