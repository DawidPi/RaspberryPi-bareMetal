//
// Created by Dawid on 12.09.2016.
//

#ifndef PIMANAGER_FUNCTIONREPRESENTATION_H
#define PIMANAGER_FUNCTIONREPRESENTATION_H

#include <QString>

namespace Common {

    class FunctionRepresentation {
    private:
        QString m_functionName;
        QString m_returnType;
        QString m_arguments;
    public:
        static FunctionRepresentation createFromText(const QString &plainText);

        FunctionRepresentation(const QString &functionName, const QString &returnType, const QString &arguments);

        FunctionRepresentation(const FunctionRepresentation &rhs);

        FunctionRepresentation(FunctionRepresentation &&rhs);

        const QString &getName() const;

        const QString &getReturnType() const;

        const QString &getArguments() const;
    };

}


#endif //PIMANAGER_FUNCTIONREPRESENTATION_H
