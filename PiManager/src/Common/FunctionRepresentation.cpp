//
// Created by Dawid on 12.09.2016.
//

#include "FunctionRepresentation.h"

#include <utility>
#include <sstream>


using namespace Common;

FunctionRepresentation::FunctionRepresentation(const FunctionRepresentation &rhs)
        : m_functionName(rhs.getName()), m_returnType(rhs.getReturnType()), m_arguments(rhs.getArguments()) {}

FunctionRepresentation::FunctionRepresentation(const QString &functionName, const QString &returnType,
                                               const QString &arguments)
        : m_functionName(functionName), m_arguments(arguments), m_returnType(returnType) {}

FunctionRepresentation::FunctionRepresentation(FunctionRepresentation &&rhs)
        : m_functionName(std::move(rhs.m_functionName)), m_arguments(std::move(rhs.m_arguments)),
          m_returnType(std::move(rhs.m_returnType)) {}

const QString &FunctionRepresentation::getName() const { return m_functionName; }

const QString &FunctionRepresentation::getReturnType() const { return m_returnType; }

const QString &FunctionRepresentation::getArguments() const { return m_arguments; }

FunctionRepresentation FunctionRepresentation::createFromText(const QString &plainText) {
    std::stringstream stream;
    stream << plainText.toStdString();

    std::string returnType;
    stream >> returnType;

    std::stringbuf functionNameBuffor;
    stream.get(functionNameBuffor, '(');
    std::string functionName(functionNameBuffor.str());

    std::string arguments;
    stream >> arguments;

    return FunctionRepresentation(functionName.c_str(), returnType.c_str(), arguments.c_str());
}
