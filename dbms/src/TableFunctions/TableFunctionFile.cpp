#include <Storages/StorageFile.h>
#include <Storages/ColumnsDescription.h>
#include <TableFunctions/TableFunctionFactory.h>
#include <TableFunctions/TableFunctionFile.h>
#include "registerTableFunctions.h"

namespace DB
{
StoragePtr TableFunctionFile::getStorage(
    const String & source, const String & format, const ColumnsDescription & columns, Context & global_context, const std::string & table_name, const std::string & compression_method) const
{
    return StorageFile::create(source,
        -1,
        global_context.getUserFilesPath(),
        getDatabaseName(),
        table_name,
        format,
        columns,
        ConstraintsDescription{},
        global_context,
        compression_method);
}

void registerTableFunctionFile(TableFunctionFactory & factory)
{
    factory.registerFunction<TableFunctionFile>();
}
}
