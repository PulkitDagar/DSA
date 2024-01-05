class solution{
    public:

    void removeOCCRE(string &s, string &part){
        int found = s.find(part);

        if(found!=string::npos){
            ///part string has been located
            //please remove it

            string left_part = s.substr(0,found);
            string right_part = s.substr(found+part.size(), s.size());

            s = left_part + right_part;

            removeOCCRE(s,part);
        }

        else{
            //base case
            return;
        }
    }

    string removeOccurances(string s, string part){

        removeOCCRE(s,part);

        return s;
    }
};