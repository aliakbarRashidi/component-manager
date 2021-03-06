#pragma once

#include <vector>

#include <QtCore/QString>
#include <QtCore/QGenericArgument>
#include <QtCore/QStringList>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>

namespace ComponentManager
{

namespace Function
{

//  Type       :  Value
// --------------------------
// "component" : "MainWindow"
// "int"       : "4"
using SignatureWithArguments =
        std::vector<std::pair<QString, QString> >;

using SignatureTypes = std::vector<QString>;

/**
   Function expects an array of the form:

   @code{.json}
     "parameters" : [
       { "component" : "MainWindow" }
     ]
   @endcode

   The result is a vector of pairs <type, value>
 */
SignatureWithArguments
parseJsonArrayToFunctionSignature(QJsonArray const& jsonArray);

/**
   Overloaded version taking array name as parameter
 */
SignatureWithArguments
parseJsonArrayToFunctionSignature(QJsonObject const& jsonObject,
                                  QString const & arrayName);

/**
   Overloaded version taking array name as parameter
 */
SignatureTypes
parseJsonArrayToFunctionSignatureTypes(QJsonObject const& jsonObject,
                                       QString const & arrayName);

using GenericArumentsWithObjects = std::pair<std::vector<QGenericArgument>,
                                             std::vector<QObject*> >;

/**
   Function creates QObjects required for passing as parameters
   to the other component constructors and wraps them
   with the macro Q_ARG() producing a vector of QGenericArgutment
 */
GenericArumentsWithObjects
createArgumentsFromSignature(SignatureWithArguments const &functionSignature);
}
}
