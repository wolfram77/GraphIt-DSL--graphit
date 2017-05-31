//
// Created by Yunming Zhang on 5/30/17.
//

#ifndef GRAPHIT_LABEL_SCOPE_H
#define GRAPHIT_LABEL_SCOPE_H

#include <list>


namespace graphit {
    /**
     * Label scope is an object that holds the current scope for the labels
     */
    class LabelScope {
    public:
        LabelScope(){

        }

        //if the statement has a statement label, then we increment the label scope
        void scope(std::string new_label_scope){
            label_scope_list_.push_back(new_label_scope);
        }

        void unscope(){
            label_scope_list_.pop_back();
        }

        ~LabelScope(){

        }

        // get the current scope string, which is used to find relevant schedule
        std::string getCurrentScope(){
            std::string concat_of_current_scope;
            for (auto label_scope : label_scope_list_){
                concat_of_current_scope = concat_of_current_scope + ": " + label_scope;
            }
            return concat_of_current_scope;
        }

    private:
        std::list<std::string> label_scope_list_;
    };
}


#endif //GRAPHIT_LABEL_SCOPE_H
